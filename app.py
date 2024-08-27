from flask import request, render_template,Flask
from werkzeug.utils import secure_filename
import os
from cve import get_cve
from cvss import get_cvss
from ai import check_vulnerabilities
from vul_type import getType
from get_description import get_description
from Countermeasures import Countermeasures
app = Flask(__name__)
@app.route('/')
def index():
    return render_template('input.html')

@app.route('/upload', methods=['POST'])
def upload_file():
    file = request.files['file-upload']
    filename = secure_filename(file.filename)
    filepath = os.path.join('./upload', filename)
    file.save(filepath)
    
    vul_obj = check_vulnerabilities(filepath)
    vul = vul_obj['vul']
    
    # 필요한 정보만 미리 계산
    codes = open(filepath).readlines()
    lines = vul_obj.get('lines', [])
    cve = get_cve(vul) if vul_obj.get('vul') == 1 else []
    cvss = get_cvss(vul) if vul_obj.get('vul') == 1 else None
    Countermeasure = Countermeasures(vul) if vul_obj.get('vul') == 1 else None
    
    return render_template(
        'output.html', 
        code=codes, 
        cve=cve, 
        cvss=cvss, 
        vul=vul, 
        vul_type=getType(vul), 
        lines=lines, 
        vul_desc=get_description(vul), 
        Countermeasures=Countermeasure
    )

    
if __name__ == '__main__':
    app.run(debug=True) 