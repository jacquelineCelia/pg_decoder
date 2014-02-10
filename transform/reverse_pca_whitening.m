function [avg, var] = reverse_pca_whitening(filein, fileout, dim, fileconfig);

load(fileconfig, 'coeff', 'latent', 'avg')
[X, counter] = load_raw_mfcc(filein, dim);
frame_num = sum(counter) / dim;

% reverse whitening
scale = diag(sqrt(latent));
scores = X * scale;

% reverse projection
X_0 = scores * inv(coeff);

% reverse shifting
X = X_0 + (ones(frame_num, 1) * avg);

save_raw_pca_whitened(X, counter, fileout, dim);
