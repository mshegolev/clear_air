import pandas as pd

df = pd.read_csv('air.csv', sep=',', index_col='DATE', parse_dates=True)
df = df.sort_index()
print(df.head())
print(df.info())
#print(df.loc['2019-03-31','PPM'].mean())
print(df.resample('H')['PPM'].mean())
import matplotlib.pyplot as plt
new_sample_df = df.loc['2019-03-31 03':'2019-03-31 08','PPM']
new_sample_df.plot()
plt.show()