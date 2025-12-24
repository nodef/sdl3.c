#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f "SDL3" ]; then return; fi
URL="https://github.com/libsdl-org/SDL/releases/download/release-3.2.28/SDL3-3.2.28.zip"
ZIP="${URL##*/}"
DIR="${ZIP%.zip}"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  rm -rf "$DIR"
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to SDL3/ ..."
rm -rf SDL3
mkdir -p SDL3
cp -rf ".build/$DIR/src"/* SDL3/
cp -rf ".build/$DIR/include/build_config"/* SDL3/
cp -rf ".build/$DIR/include/SDL3"/* SDL3/
}


# Test the project
test() {
echo "Running 01-basic-window.c ..."
clang -I. -o 01.exe examples/01-basic-window.c  && ./01.exe && echo -e "\n"
# echo "Running 02-event-handling.c ..."
# clang -I. -o 02.exe examples/02-event-handling.c    && ./02.exe && echo -e "\n"
# echo "Running 03-drawing-rectangles.c ..."
# clang -I. -o 03.exe examples/03-drawing-rectangles.c  && ./03.exe && echo -e "\n"
# echo "Running 04-audio-playback.c ..."
# clang -I. -o 04.exe examples/04-audio-playback.c && ./04.exe && echo -e "\n"
# echo "Running 05-texture-rendering.c ..."
# clang -I. -o 05.exe examples/05-texture-rendering.c   && ./05.exe && echo -e "\n"
# echo "Running 06-game-loop.c ..."
# clang -I. -o 06.exe examples/06-game-loop.c      && ./06.exe && echo -e "\n"
# echo "Running 07-joystick-input.c ..."
# clang -I. -o 07.exe examples/07-joystick-input.c   && ./07.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
