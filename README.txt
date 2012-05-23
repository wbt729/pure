This is Pure the PUlse REmote measurement utility. This tool is still in 
its experimental stage.

Pure is a demonstrator of a biomedical measurement procedure called remote 
Photoplethysmography. It uses a camera to measure color changes of the 
skin that result from bloodflow. Thereby the heartbeat can be detected 
remotely.
Pure makes use of OpenCV for image acquisition and processing and Qt for 
user-interface stuff. Sadly it also makes use of Qt for signal processing, 
since no promising library for signal processing has been sigthed.
This one might be it though: https://github.com/vinniefalco/DSPFilters

Pure consists of a signal chain implemented as:

Input                 Chainlink          Output
-------------------------------------------------
camera (real life) -> (Frame-)Grabber -> cv::Mat
cv::Mat            -> ImageProcessor  -> 3*double
3*double           -> SignalProcessor -> 3*double
3*double           -> MeanPlot

The elements of the signal chain are connected through Qt's signal and 
slot mechanism. The framegrabber is connected to the image processor. The 
image processor extracts three samples from each image, corresponding to 
the three color channels reg, green and blue.
These three samples are sent to the signal processor. The signal processor 
performs the same operations on the sample of each channel:
The sample is added to an input buffer, processed (i.e. filtered) and the 
filtered output is added to an output buffer. The in- and output buffers 
contain the two time-series limited to the buffer size.
The output of the signal processor is sent to a time-series plot called 
mean-plot.

In order to make this program grow you can implement your own image 
processing or singal processing algorithms. You can also implement new 
widgets in form of the FFTWidget, that access data at any part of the 
singal chain, by connecting to the outputs of Grabber, ImageProcessor or 
SignalProcessor.
