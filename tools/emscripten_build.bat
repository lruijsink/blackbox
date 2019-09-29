cd ..
if not exist build md build
cd build
if not exist emscripten md emscripten
cd emscripten
call emconfigure cmake ../..
call emmake make
pause