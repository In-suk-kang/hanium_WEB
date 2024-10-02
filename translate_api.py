from googletrans import Translator

def translate(text):
    translator = Translator()
    res = translator.translate(text,src='en',dest='ko')
    return res.text