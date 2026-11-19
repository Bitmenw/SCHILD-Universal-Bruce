#include "schild/GpsNmeaParser.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

namespace schild {
namespace {
bool parseTime(const char* s, uint32_t& ms) {
  if (!s || strlen(s) < 6) return false;
  for (int i=0;i<6;i++) if (s[i]<'0'||s[i]>'9') return false;
  int h=(s[0]-'0')*10+s[1]-'0', m=(s[2]-'0')*10+s[3]-'0', sec=(s[4]-'0')*10+s[5]-'0';
  if (h>23 || m>59 || sec>60) return false;
  ms=static_cast<uint32_t>(((h*60+m)*60+sec)*1000);
  const char* dot=strchr(s,'.');
  if(dot && dot[1]>='0' && dot[1]<='9') ms+=(dot[1]-'0')*100;
  if(dot && dot[2]>='0' && dot[2]<='9') ms+=(dot[2]-'0')*10;
  if(dot && dot[3]>='0' && dot[3]<='9') ms+=(dot[3]-'0');
  return true;
}
bool coordinate(const char* v,const char* hemi,double& out) {
  if(!v||!hemi||!*v||!*hemi) return false;
  double raw=atof(v); int deg=static_cast<int>(raw/100.0);
  double min=raw-deg*100.0; if(min<0||min>=60) return false;
  out=deg+min/60.0;
  if(hemi[0]=='S'||hemi[0]=='W') out=-out;
  else if(hemi[0]!='N'&&hemi[0]!='E') return false;
  if((hemi[0]=='N'||hemi[0]=='S')&&fabs(out)>90) return false;
  if((hemi[0]=='E'||hemi[0]=='W')&&fabs(out)>180) return false;
  return true;
}
int fields(char* s,char* f[],int max) {
  int n=0; f[n++]=s;
  while(*s && n<max) { if(*s==','){*s='\\0';f[n++]=s+1;} ++s; }
  return n;
}
void parseDate(const char* s,GpsFix& o) {
  if(!s||strlen(s)!=6) return;
  for(int i=0;i<6;i++) if(s[i]<'0'||s[i]>'9') return;
  o.day=(s[0]-'0')*10+s[1]-'0'; o.month=(s[2]-'0')*10+s[3]-'0';
  int y=(s[4]-'0')*10+s[5]-'0'; o.year=static_cast<uint16_t>(y>=80?1900+y:2000+y);
  o.hasDate=o.day>=1&&o.day<=31&&o.month>=1&&o.month<=12;
}
}
bool GpsNmeaParser::checksumValid(const char* s) {
  if(!s||s[0]!='$') return false;
  const char* star=strchr(s,'*'); if(!star||!star[1]||!star[2]) return false;
  unsigned char sum=0; for(const char* p=s+1;p<star;p++) sum^=static_cast<unsigned char>(*p);
  char* end=nullptr; long expected=strtol(star+1,&end,16);
  return end==star+3&&expected>=0&&expected<=255&&sum==expected;
}
bool GpsNmeaParser::parseLine(const char* line,GpsFix& out) const {
  if(!checksumValid(line)) return false;
  char b[128]; size_t len=strlen(line); if(len>=sizeof(b)) return false;
  memcpy(b,line+1,len-1); b[len-1]='\\0';
  char* star=strchr(b,'*'); if(!star) return false; *star='\\0';
  char* f[20]; int n=fields(b,f,20); if(n<2) return false;
  bool rmc=strstr(f[0],"RMC")!=nullptr, gga=strstr(f[0],"GGA")!=nullptr;
  if(!rmc&&!gga) return false;
  uint32_t t=0; if(!parseTime(f[1],t)) return false; out.utcMillisOfDay=t;
  if(rmc) {
    if(n<10) return false;
    if(f[2][0]!='A'){out.valid=false;return true;}
    if(!coordinate(f[3],f[4],out.latitudeDeg)||!coordinate(f[5],f[6],out.longitudeDeg)) return false;
    out.valid=true;
    if(f[7][0]){out.speedKnots=atof(f[7]);out.hasSpeed=true;}
    if(f[8][0]){out.courseDeg=atof(f[8]);out.hasCourse=true;}
    parseDate(f[9],out); return true;
  }
  if(n<10) return false;
  if(f[6][0]!='1'&&f[6][0]!='2'&&f[6][0]!='4'&&f[6][0]!='5'){out.valid=false;return true;}
  if(!coordinate(f[2],f[3],out.latitudeDeg)||!coordinate(f[4],f[5],out.longitudeDeg)) return false;
  out.valid=true; out.satellites=static_cast<uint8_t>(atoi(f[7]));
  if(f[9][0]){out.altitudeMeters=atof(f[9]);out.hasAltitude=true;}
  return true;
}
}  // namespace schild
