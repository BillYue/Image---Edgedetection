mex image_threshold.c
img = imread('threshold-test.png');
img = im2double(img);

out1 = image_threshold (img , 0.25);
out2 = image_threshold (img , 0.5);
out3 = image_threshold (img , 0.75);

figure(1)

imshow(out1);
title('Threshold T = 0.25')
figure(2)
imshow(out2);
title('Threshold T = 0.50')
figure(3)
imshow(out3);
title('Threshold T = 0.75')