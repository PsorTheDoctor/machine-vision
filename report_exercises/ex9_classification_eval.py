import numpy as np
import matplotlib.pyplot as plt
from sklearn import metrics

total = 300
tp = 113
fp = 21
tn = 168 - fp
fn = 132 - tp

conf_matrix = np.array([[tn, fp],
                        [fn, tp]])
display = metrics.ConfusionMatrixDisplay(conf_matrix)
display.plot()
plt.show()

print('Accuracy:', round((tp + tn) / total, 4))
print('Presision: ', round(tp / (tp + fp), 4))
print('Recall:', round(tp / (tp + fn), 4))
