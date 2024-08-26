from flask import request, render_template,Flask
from werkzeug.utils import secure_filename
import os
from cve import get_cve
from cvss import get_cvss
from ai import check_vulnerabilities
from vul_type import getType
from get_description import get_description
app = Flask(__name__)
@app.route('/')
def index():
    return render_template('input.html')

@app.route('/upload',methods = ['POST'])
def upload_file():
    file = request.files['file-upload']
    filename = secure_filename(file.filename)
    filepath = os.path.join('./upload',filename)
    file.save(filepath)
    vul_obj = check_vulnerabilities(filepath)
    lines = []
    cve = []
    vul = vul_obj['vul']
    vul_type = getType(vul)
    vul_desc = get_description(vul)
    if vul_obj.get('vul') == 1:
       lines = vul_obj['lines']
       cve = get_cve(vul)
    cvss = get_cvss(vul)
    #------------------------------------------------
    codes = []
    with open(filepath, 'r') as file:
        codes = file.readlines()
    #------------------------------------------------
    return render_template('output.html',code=codes,cve=cve,cvss=cvss,vul = vul,vul_type = vul_type,lines = lines,vul_desc = vul_desc)
    
if __name__ == '__main__':
    app.run(debug=True) 