# Project status

## Current state

- [x] Public repository created.
- [x] Initial scope and safety boundaries documented.
- [x] Hardware validation requirements documented.
- [ ] Identify the exact Bruce firmware repository and commit/tag installed on the device.
- [ ] Identify the exact CYD/ESP32 board model and revision.
- [ ] Confirm GPS receiver model and wiring.
- [ ] Confirm nRF24 module model and wiring, if present.
- [ ] Design the Bruce adapter against the real source tree.
- [ ] Add verified board profiles and build targets.
- [ ] Build and test each target separately.
- [ ] Publish binaries only after physical-device validation.

## Needed before firmware integration

Please provide:

1. A photo of the front and back of the board, or its exact product/model name.
2. The Bruce version or the link to the exact Bruce source/release used on the device.
3. The GPS receiver model and how it is connected.
4. Whether the nRF24L01+ module is already connected, and its wiring if known.

Do not flash an experimental build until the target profile has been verified.