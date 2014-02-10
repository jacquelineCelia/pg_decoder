function X_pca = do_pca_with_computed_rotation(filein, fileout, dim, fileconfig);

load(fileconfig, 'coeff', 'latent', 'avg')
[X, counter] = load_raw_mfcc(filein, dim);

frame_num = sum(counter)/dim

X_0 = X - (ones(frame_num, 1) * avg);

scores = X_0 * coeff;

X_pca = whitening(scores, latent);

var(X_pca)

save_raw_pca_whitened(X_pca, counter, fileout, dim);
