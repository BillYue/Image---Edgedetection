mex spatial_filter.c
img = imread('lena_gray.jpg');
img = im2double(img);
guas_k_1 = (1/331).*[1 4 7 4 1; 4 20 33 20 4; 7 33 55 33 7; 4 20 33 20 4; 1 4 7 4 1]; %gaussian filter for sigma = 1

guas_k_1_pt_6 = [0.017056 0.030076 0.036334 0.030076 0.017056;0.030076 0.053035 0.064071 0.053035 0.030076;0.036334 0.064071 0.077404 0.064071 0.036334;0.030076 0.053035 0.064071 0.053035 0.030076;0.017056 0.030076 0.036334 0.030076 0.017056];
out1 = spatial_filter(img, guas_k_1);
out2 = spatial_filter(img, guas_k_1_pt_6);
figure(1); imshow(out1)
figure(2); imshow(out2)