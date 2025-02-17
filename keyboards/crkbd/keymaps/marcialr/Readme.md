qmk compile -kb crkbd/rev1 -km marcialr
qmk flash -kb crkbd/rev1 -km marcialr



Chrome functions: 
F1 history back 
F2 History forward 
F3 reload page
F4 full screen
F6 workspaces
F6 LIGNT down
F7 LIGNT up
F8 SOUND OFF
F9 SOUND down
F10 SOUND up
F11 FULL SCREEN TOO
F12 Javascript console







LT(layer, kc)	Turn on layer when held, kc when tapped
TO(layer)	Turns on layer and turns off all other layers, except the default layer

DF(layer)	Set the base (default) layer until the keyboard loses power
PDF(layer)	Set the base (default) layer in EEPROM
MO(layer)	Momentarily turn on layer when pressed (requires KC_TRNS on destination layer)
OSL(layer)	Momentarily activates layer until a key is pressed. See One Shot Keys for details.
TG(layer)	Toggle layer on or off
TT(layer)	Normally acts like MO unless it's tapped multiple times, which toggles layer on




LM(layer, mod)	Momentarily turn on layer (like MO) with mod active as well. Where mod is a mods_bit. Mods can be viewed here. Example Implementation: LM(LAYER_1, MOD_LALT)






TODO

detect 2xSpace
    Two keys combination as a trigger for macro (or anything else) - https://github.com/qmk/qmk_firmware/issues/817
TAP-HOLD


