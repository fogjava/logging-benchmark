import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("results/logging.csv")
print(df.columns)
df_group = df.groupby('logger')['logs_per_s'].mean().reset_index()

plt.figure(figsize=(10, 6))
plt.bar(df_group['logger'], df_group['logs_per_s'], color = ['blue', 'green'])

plt.ylabel("Logs per second")
plt.title("glog vs spdlog benchmark")

plt.savefig("results/logging_comparison.png")
plt.show()


