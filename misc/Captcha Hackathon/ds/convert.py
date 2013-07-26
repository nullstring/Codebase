from PIL import Image 
for i in range(5000):
	im = Image.open ("../divided_images/"+str(i)+".png")
	im_file = im.convert('1') # convert image to black and white
	im_file.save(str(i)+".png")
