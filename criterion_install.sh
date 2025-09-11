#!/bin/bash

python -m venv ~/criterion_venv
. ~/criterion_venv/bin/activate 
pip install meson
pip install ninja
cd
if [ ! -d "Criterion" ]; then
    git clone https://github.com/Snaipe/Criterion.git
fi
cd Criterion
meson build
ninja -C build
deactivate
rm -rf ~/criterion_venv