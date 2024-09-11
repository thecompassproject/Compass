mkdir ThirdPartyLib
cd ThirdPartyLib
git clone https://github.com/pybind/pybind11.git 
cd ..
python -m venv venv
venv/bin/activate.bat
pip install -r requirements.txt
build_script.bat