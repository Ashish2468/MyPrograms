from gtts import gTTS
import os


abc=open("samplee.txt")
text = abc.read()

language = 'en'

obj = gTTS(text = text,lang =language,slow=False)

obj.save("sample3.mp3")#for saving the object

os.system("sample3.mp3")
