pyinstaller --name=compass website\start.py --copy-metadata django-bootstrap-v5 --noconfirm --add-data=website\algorithms\templates:algorithms\templates
xcopy website\algorithms\programcodes dist\compass\algorithms\programcodes /e /i /h
xcopy website\algorithms\static dist\compass\_internal\algorithms\static /e /i /h
xcopy website\CodeBlocks dist\compass\CodeBlocks /e /i /h