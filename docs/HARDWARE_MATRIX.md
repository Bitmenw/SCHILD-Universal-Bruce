# Hardware compatibility and validation matrix

This document tracks intended support, not confirmed compatibility.

| Hardware family | Planned role | What must be confirmed |
|---|---|---|
| CYD 2.8 inch | Display/UI target | Exact board revision, ESP32 module, display driver, touch controller, pinout |
| CYD 3.5 inch | Display/UI target | Exact board revision, display driver, touch controller, pinout |
| ESP32 classic | Core target | Exact module, flash size, available GPIO, attached display |
| ESP32-S2 | Core target | Board definition, USB/display wiring, peripheral availability |
| ESP32-S3 | Core target | Board definition, PSRAM/flash, display and peripheral wiring |
| ESP32-C5 | Future evaluation | Framework/toolchain support and peripheral compatibility must be checked before enabling builds |
| nRF24L01+ | Optional 2.4 GHz receiver | Module variant, SPI wiring, power stability, antenna, receive-only implementation |
| GPS receiver | Optional location source | Receiver model, UART/I2C interface, voltage levels, pin assignment, antenna placement |
| External RF/ELF sensor | Optional measurement source | Exact sensor model, range, calibration, interface, units, uncertainty |

## Release gate for each board

A board profile is considered supported only after all of the following are recorded:

- Exact board name and revision, with a reliable pinout reference.
- Display and touch controller identified and initialized.
- GPIO conflicts checked for display, touch, SPI, UART, GPS, and sensors.
- Power requirements checked, especially for nRF24 transmit-capable modules; SCHILD features must remain receive-only.
- Firmware builds successfully for the declared target.
- Device boots and the display/UI is tested on physical hardware.
- GPS and sensor readings are checked against known references where applicable.
- The matching Bruce revision and integration method are documented.

A successful compile alone does not establish hardware compatibility.