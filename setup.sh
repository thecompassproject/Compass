mkdir ThirdPartyLib
cd ThirdPartyLib
git clone https://github.com/pybind/pybind11.git 
cd ..
python -m venv venv
source venv/bin/activate
pip install -r requirements.txt
build_script.sh
cd website
python manage.py runserver
