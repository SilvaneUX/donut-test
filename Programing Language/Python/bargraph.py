#code to create a simple bar graph
d1={
    "hp":20,
    "Sony":30,
    "Lenovo":40,
    "Dell":30,
    "Alenware":20
}
brand=list(d1.keys())
sales=list(d1.values())
plt.bar(brand,sales,color="red",width=0.3)
plt.title("sales of laptop")
plt.show()