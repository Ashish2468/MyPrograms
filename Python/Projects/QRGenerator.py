import qrcode
import image

qr=qrcode.QRCode(
version = 15,
box_size=10,
border =5
)

data ="https://www.youtube.com/watch?v=onHPipeASdk"

qr.add_data(data)

qr.make(fit=Tbrue)
image = qr.make_image(fit="black",back_color="white")
image.save("test.png")