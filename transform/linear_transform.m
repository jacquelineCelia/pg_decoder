function [A] = linear_transform(filein, fileTarget, fileout, dim);

[X, counter] = load_raw_mfcc(filein, dim);
muB = mean(X);

[Y, counter1] = load_raw_mfcc(fileTarget, dim);
muA = mean(Y);

A = 

[coeff, scores, latent] = get_pca(X, counter);

save('timit_jnas.mat', 'coeff', 'latent', 'avg', '-v7.3');

X = whitening(scores, latent); 

save_raw_pca_whitened(X, counter, fileout, dim);
