function compute_rotation(fn_target_sil, fn_target_speech, fn_sil, fn_speech, dim, fout);

[target_sil, target_sil_c] = load_raw_mfcc(fn_target_sil, dim);
[target_sp, target_sp_c] = load_raw_mfcc(fn_target_speech, dim);
[sil, sil_c] = load_raw_mfcc(fn_sil, dim);
[sp, sp_c] = load_raw_mfcc(fn_speech, dim);

target_sil_mean = mean(target_sil);
target_sp_mean = mean(target_sp);
sil_mean = mean(sil);
sp_mean = mean(sp); 

A = [[sil_mean, 1] ; [sp_mean, 1]]';
b = [[target_sil_mean, 1] ; [target_sp_mean, 1]]';

x = (A' \ b')';
save(fout, 'x', '-v7.3');

size(x)
size(A)
size(b)

x * A
b

