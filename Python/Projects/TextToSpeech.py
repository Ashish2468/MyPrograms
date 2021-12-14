from gtts import gTTS
import os


abc=open("samplee.txt")
text = abc.read()

language = 'en'

obj = gTTS(text = text,lang =language,slow=False)

obj.save("sample3.mp3")

os.system("sample3.mp3")