# Beekeeb Toucan Keyboard

I have a new programmable keyboard [beekeeb toucan](https://docs.beekeeb.com/toucan-keyboard/quick-start-keymap-and-firmware).
I already have some keyboard layouts that I am using frequently:

- [zsh voyager layout](/home/cmiu/work/ai-diverse/zmk-keyboard-toucan/doc/moonlander/)
- [framework laptop](/home/cmiu/work/ai-diverse/zmk-keyboard-toucan/doc/framework/)

We have successfully created a new custom keyboard layout for the Beekeeb Toucan that perfectly replicates the custom workflows and key features from both reference layouts.

---

## Current Toucan Keyboard Layout Map

### 1. Base Layer (BASE - 0)

Our Base Layer includes **Home Row Mods** (tap for key, hold for modifier), **E-triggered navigation layer activation**, and a **Tap-Dance on ESC** for Caps Lock.

| Row | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 | Col 11 | Col 12 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Row 1** | `ESC` / `CAPS` *(TD)* | `Q` | `W` | `E` / `mo NAV` | `R` | `T` | `Y` | `U` | `I` | `O` | `P` | `BSPC` |
| **Row 2** | `TAB` / `LSHFT` | `A` / `LCTRL` | `S` / `LGUI` | `D` / `LALT` | `F` | `G` | `H` | `J` | `K` / `RALT` | `L` / `RGUI` | `;` / `RCTRL` | `'` / `RSHFT` |
| **Row 3** | `LSHFT` | `Z` | `X` | `C` | `V` | `B` | `N` | `M` | `,` | `.` | `/` | `RSHFT` |

#### Base Thumb Cluster (Left / Right from outer to inner):
* **L1 (outermost):** `Backspace` (`&kp BSPC`)
* **L2 (middle):** `Delete` (`&kp DEL`)
* **L3 (innermost):** `mo NAV` (Layer 1)
* **R1 (innermost):** `mo SYM` (Layer 2)
* **R2 (middle):** `Enter` (`&kp RET`)
* **R3 (outermost):** `Space` (`&kp SPACE`)

---

### 2. Navigation Layer (NAV - 1)

Activated temporarily by holding **L3** or QWERTY **E** (`&lt NAV E`). Features Bluetooth profiles on the left hand and quick cursor/navigation keys on your right hand resting positions.

| Row | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 | Col 11 | Col 12 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Row 1** | `_` | `1` | `2` | `3` | `4` | `5` | `_` | `HOME` | `PG_UP` | `PG_DN` | `END` | `_` |
| **Row 2** | `BT_CLR` | `BT_SEL 0` | `BT_SEL 1` | `BT_SEL 2` | `BT_SEL 3` | `BT_SEL 4` | `_` | `LEFT` | `DOWN` | `UP` | `RIGHT` | `_` |
| **Row 3** | `_` | `studio_unlock` | `_` | `_` | `_` | `_` | `_` | `_` | `_` | `_` | `_` | `_` |

*Note: All thumb keys are set to `&trans` on this layer, seamlessly passing through your Base thumb keys (Backspace, Delete, Enter, Space).*

---

### 3. Symbol / Numpad Layer (SYM - 2)

Activated by holding **R1** (`&mo SYM`). Emulates the Voyager layout with vertically stacked programmer symbols (`{}`, `()`, `[]`) on the left hand, and a full numeric keypad on the right hand.

| Row | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 | Col 11 | Col 12 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Row 1** | `_` | `!` | `@` | `{` | `}` | `\|` | `UP` | `7` | `8` | `9` | `*` | `BSPC` |
| **Row 2** | `_` | `#` | `$` | `(` | `)` | `` ` `` | `DOWN` | `4` | `5` | `6` | `+` | `_` |
| **Row 3** | `_` | `%` | `^` | `[` | `]` | `~` | `&` | `1` | `2` | `3` | `\` | `_` |

*Note: All thumb keys are set to `&trans` on this layer, passing through your Base thumb keys.*

---

### 4. Adjust Layer (ADJ - 3)

Automatically activated when holding both **L3** (`mo NAV`) and **R1** (`mo SYM`) together (*tri-layer* behavior).

| Row | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 | Col 11 | Col 12 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Row 1** | `mo TAB` | `_` | `F7` | `F8` | `F9` | `F12` | `VOL_DN` | `MUTE` | `VOL_UP` | `_` | `_` | `BSPC` |
| **Row 2** | `LCTRL` | `_` | `F4` | `F5` | `F6` | `F11` | `_` | `_` | `_` | `_` | `_` | `_` |
| **Row 3** | `bt LSHFT`| `_` | `F1` | `F2` | `F3` | `F10` | `_` | `_` | `_` | `_` | `_` | `_` |
