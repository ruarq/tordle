# Tordle - Terminal Wordle
It's wordle in the terminal!

## Build instructions
### Linux
Dependencies: `g++`, `make` and `git`

Clone:
```bash
git clone https://github.com/ruarq/tordle.git
```

Compile:
```bash
cd tordle
./premake5 gmake2
make config=release
cp bin/release/tordle tordle
```

Run:
```bash
./tordle
```

### Windows
Sorry!