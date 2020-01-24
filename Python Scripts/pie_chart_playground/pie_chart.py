import plotly.graph_objects as go

'''
labels = ['Oxygen','Hydrogen','Carbon_Dioxide','Nitrogen']
values = [4500, 2500, 1053, 500]

# Use `hole` to create a donut-like pie chart
fig = go.Figure(data=[go.Pie(labels=labels, values=values, hole=.3)])
fig.show()
'''

labels = ['Sleep','class','recreation']
values = [8.5, 2.5, 13]

fig = go.Figure(data=[go.Pie(labels=labels, values = values, hole=.4)])
fig.update_layout(font=dict(
    family="Courier New, monospace",
    size=24
))
fig.show()