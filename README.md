# vernam

Vernam Cipher encoder/decoder

## Installation

```bash
make && sudo make install
```

## Usage

```
Usage: ./vernam [--help] [--table] [--row <row>] [--pad <pad>]
                [--key <key>] [--cipher <cipher>] [--text <text>]
```

| Flag                    | Notes                                            |
|-------------------------|--------------------------------------------------|
| --help                  | Display above usage message                      |
| --table                 | Generates/displays the cipher table              |
| --row &lt;row&gt;       | Starting row (26 characters) of the cipher table |
| --pad &lt;pad&gt;       | Increment by row (can be positive or negative)   |
| --key &lt;key&gt;       | Secret key used to encode/decode                 |
| --cipher &lt;cipher&gt; | Message to decode                                |
| --text &lt;text&gt;     | Message to encode                                |

## Example

*Table display for manual encoding/decoding*

```
./vernam --row zyxwvutsrqponmlkjihgfedcba --pad -1 --table
```

Output:

```
 ABCDEFGHIJKLMNOPQRSTUVWXYZ
Azyxwvutsrqponmlkjihgfedcba
Byxwvutsrqponmlkjihgfedcbaz
Cxwvutsrqponmlkjihgfedcbazy
Dwvutsrqponmlkjihgfedcbazyx
Evutsrqponmlkjihgfedcbazyxw
Futsrqponmlkjihgfedcbazyxwv
Gtsrqponmlkjihgfedcbazyxwvu
Hsrqponmlkjihgfedcbazyxwvut
Irqponmlkjihgfedcbazyxwvuts
Jqponmlkjihgfedcbazyxwvutsr
Kponmlkjihgfedcbazyxwvutsrq
Lonmlkjihgfedcbazyxwvutsrqp
Mnmlkjihgfedcbazyxwvutsrqpo
Nmlkjihgfedcbazyxwvutsrqpon
Olkjihgfedcbazyxwvutsrqponm
Pkjihgfedcbazyxwvutsrqponml
Qjihgfedcbazyxwvutsrqponmlk
Rihgfedcbazyxwvutsrqponmlkj
Shgfedcbazyxwvutsrqponmlkji
Tgfedcbazyxwvutsrqponmlkjih
Ufedcbazyxwvutsrqponmlkjihg
Vedcbazyxwvutsrqponmlkjihgf
Wdcbazyxwvutsrqponmlkjihgfe
Xcbazyxwvutsrqponmlkjihgfed
Ybazyxwvutsrqponmlkjihgfedc
Zazyxwvutsrqponmlkjihgfedcb
```

*Encode a message*

```
./vernam --row zyxwvutsrqponmlkjihgfedcba --pad -1 --key test --text attackatdawn
```

Output:

```
gcogelhndvlt
```

*Decode a message*

```
./vernam --row zyxwvutsrqponmlkjihgfedcba --pad -1 --key test --text gcogelhndvlt
```

Output:

```
attackatdawn
```

## Explanation

Read more about the [Gilbert Vernam](https://en.wikipedia.org/wiki/Gilbert_Vernam) and his cipher ([one-time pad](https://en.wikipedia.org/wiki/One-time_pad)).
