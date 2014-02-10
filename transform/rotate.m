function rotate(filein, fileout, rot, dim);

[data_x, data_c] = load_raw_mfcc(filein, dim);
load(rot, 'x');

frame_num = sum(data_c) / dim;

data_x = [data_x' ; ones(1, frame_num)];

rotated_data = x * data_x;

rotated_data = rotated_data(1:39, :)';

save_raw_pca_whitened(rotated_data, data_c, fileout, dim);
