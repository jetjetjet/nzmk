/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>

#define DEFAULT 0
#define LOWER   1
#define RAISE   2

/ {
    keymap {
        compatible = "zmk,keymap";
        default_layer {
// ------------------------------------------------------------------------------------------------------------
// | ESC      |  1     | 2      |  3     |  4      |  5      |                         |  6       |  7      |  8       |  9      |  0       | BKSPC   |
// | GRAVE    |  Q     | W      |  E     |  R      |  T      |                         |  Y       |  U      |  I       |  O      |  P       |  {      |
// |  TAB     |  A     |  S     |  D     |  F      |  G      |                         |  H       |  J      |  K       |  L      |   ;      |   '     |
// | SHIFT    |  Z     |  X     |  C     |  V      |  B      |  MUTE     |  |          |  N       |  M      |  ,       |  /      |   -      |  +      |
//                     | GUI    | ALT    | CTRL    | ENTER   | LOWER     |  |  RAISE   | SPACE    | CTRL+X  | CTRL+C   | CTRL+V  |

            bindings = <
&kp ESC    &kp N1   &kp N2   &kp N3   &kp N4     &kp N5                             &kp N6    &kp N7    &kp N8    &kp N9     &kp N0     &kp BSPC 
&kp GRAVE  &kp Q    &kp W    &kp E    &kp R      &kp T                              &kp Y     &kp U     &kp I      &kp O     &kp P      &kp LBKT 
&kp TAB    &kp A    &kp S    &kp D    &kp F      &kp G                              &kp H     &kp J     &kp K      &kp L     &kp SEMI   &kp SQT  
&kp LSHFT  &kp Z    &kp X    &kp C    &kp V      &kp B    &kp C_MUTE     &none      &kp N     &kp M     &kp COMMA  &kp SLASH &kp MINUS  &kp EQUAL
                    &kp LGUI &kp LALT &kp LCTRL  &kp RET  &mo LOWER      &mo RAISE  &kp SPACE &kp LC(X) &kp LC(C)  &kp LC(v)
            >;

            sensor-bindings = <&inc_dec_kp UP_ARROW DOWN_ARROW &inc_dec_kp LEFT_ARROW RIGHT_ARROW>;
        };

        lower_layer {
// ------------------------------------------------------------------------------------------------------------
// | F1  | F2  | F3  | F4   | F5   | F6    |            |     | ^   |     |     |     | DEL |
// | F7  | F8  | F9  | F10  | F11  | F12   |            | <-  | v   | ->  |     |     |  }  |
// |     |     |     |      |      |       |            |     |     |     |     |     |     |
// |     |     |     |      |      | HOME  |    |  |    | END |     |  .  |     |     |     |
//             |     |      |      |       |    |  |    |     |     |     |     |
                                                      
            bindings = <
&kp F1   &kp F2   &kp F3   &kp F4   &kp F5   &kp F6                      &trans    &kp UP    &trans     &trans   &trans   &kp DEL 
&kp F7   &kp F8   &kp F9   &kp F10  &kp F11  &kp F12                     &kp LEFT  &kp DOWN  &kp RIGHT  &trans   &trans   &kp RBKT 
&trans   &trans   &trans   &trans   &trans   &trans                      &trans    &trans    &trans     &trans   &trans   &trans  
&trans   &trans   &trans   &trans   &trans   &kp HOME  &trans   &trans   &kp END   &trans    &kp PERIOD &trans   &trans   &trans
                  &trans   &trans   &trans   &trans    &trans   &trans   &trans    &trans    &trans     &trans   
            >;

            sensor-bindings = <&inc_dec_kp C_VOL_UP C_VOL_DN &inc_dec_kp PG_UP PG_DN>;
        };

        raise_layer {
// ------------------------------------------------------------------------------------------------------------
// |BTCLR | BT1  | BT2  |  BT3  | BT4  |  BT5  |            |      |    |    |    |    |    |
// |      | INS  | PSCR | GUI   |      |       |            | PGUP |    |    |    |    |    |
// |      | ALT  | CTRL | SHIFT |      | CAPS  |            | PGDN |    |    |    |    |    |
// |      |      |      |       |      |  HOME |    |  |    |      |    |    |    |    |    |
//               |      |       |      |       |    |  |    |      |    |    |    |

            bindings = <
&bt BT_CLR  &bt BT_SEL 0 &bt BT_SEL 1 &bt BT_SEL 2 &bt BT_SEL 3 &bt BT_SEL 4                    &trans    &trans  &trans  &trans  &trans  &trans
&trans      &kp INS      &kp PSCRN    &kp K_CMENU  &trans       &trans                          &kp PG_UP &trans  &trans  &trans  &trans  &trans 
&trans      &kp LALT     &kp LCTRL    &kp LSHFT    &trans       &kp CLCK                        &kp PG_DN &trans  &trans  &trans  &trans  &trans  
&trans      &trans       &trans       &trans       &trans       &kp HOME     &trans    &trans   &trans    &trans  &trans  &trans  &trans  &trans
                         &trans       &trans       &trans       &trans       &trans    &trans   &trans    &trans  &trans  &trans 
            >;

            sensor-bindings = <&inc_dec_kp C_VOL_UP C_VOL_DN &inc_dec_kp PG_UP PG_DN>;
        };
    };
};

