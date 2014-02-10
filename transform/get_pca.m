function [coeff, score, latent] = get_pca(X, counter);

[coeff, score, latent] = princomp(X);
