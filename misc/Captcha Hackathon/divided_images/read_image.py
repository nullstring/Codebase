import Image


for i in range(1000):
	im = Image.open ("../complete_images/image"+str(i+1)+".png")
	width, height = im.size
	
	wd = width/5
	for j in range (5):
		out = str (5*i+j) + ".png"
		box = (j*wd, 0, (j+1)*wd, height)
		im_show = im.crop (box).save (out)		
