# Tordle - Terminal Wordle
It's wordle in the terminal!

## Build instructions
### Linux & MacOS
Dependencies: `g++` and `make`

Clone:
```bash
git clone https://github.com/ruarq/tordle.git
```

Compile:
```bash
cd tordle
premake/linux gmake2 # premake/macos for MaxOS
make config=release
cp bin/release/tordle tordle
```

Run:
```bash
./tordle
```
