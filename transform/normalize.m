function normalize(target, filein, fileout, dim);

[target_x, target_c] = load_raw_mfcc(target, dim);
target_mean = mean(target_x);
target_std = std(target_x);

[data_x, data_c] = load_raw_mfcc(filein, dim);
frame_num = sum(data_c)/dim;

data_std = std(data_x);
data_scaled = data_x .* (ones(frame_num, 1) * (target_std ./ data_std));

data_mean = mean(data_scaled);
data_shift = data_scaled - (ones(frame_num, 1) * (data_mean - target_mean));

save_raw_pca_whitened(data_shift, data_c, fileout, dim);
