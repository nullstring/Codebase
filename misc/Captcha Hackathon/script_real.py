from pybrain.structure import FeedForwardNetwork, LinearLayer, SigmoidLayer, FullConnection, RecurrentNetwork
from pybrain.tools.shortcuts import buildNetwork
from pybrain.datasets import SupervisedDataSet
from PIL import Image
import os
from pybrain.supervised.trainers import BackpropTrainer

n_input_size = 3250
n_middle_size = 1000
n_output_size = 36

net = buildNetwork(n_input_size,n_middle_size,n_output_size)

#get dataset
ds = SupervisedDataSet(n_input_size,n_output_size)
ds_directory = "./ds"

os.chdir(ds_directory)
for files in os.listdir("."):
        if files.endswith(".png"):
                    label = (ord(files[0]), )            #ord() for chat to ascii , chr() to ascii to char
                    image = Image.open(files)
                    pixels = tuple(image.getdata())
                    #print len(pixels)
                    #print label
                    ds.addSample(pixels,label)


#print type(ds['target'])
trainer = BackpropTrainer(net, ds)
trainer.train();
