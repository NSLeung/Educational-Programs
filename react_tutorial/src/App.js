import React from 'react';
import { Component } from 'react';
// import logo from './logo.svg';
import { BrowserRouter as Router, Route } from 'react-router-dom';
import './App.css';
import Todos from './components/Todos'
import Header from './components/layout/Header'
import AddTodo from './components/AddTodo'
import About from './components/pages/About'
// import uuid from 'uuid'
import axios from 'axios'

// function App() {
class App extends Component{
  //add state here 
  state = {
    todos: [
      // {
      //   id: uuid.v4(),
      //   title: 'Take out the trash',
      //   completed: false
      // },
      // {
      //   id: uuid.v4(),
      //   title: 'Dinner with Joey',
      //   completed: false
      // },
      // {
      //   id: uuid.v4(),
      //   title: 'Do Homework',
      //   completed: false
      // }-
    ]
  }

    //another lifecycle method (like render)
    componentDidMount(){
      axios.get('https://jsonplaceholder.typicode.com/todos?_limit=10')
      .then(res => this.setState({todos: res.data}))
    }

    // Toggle completed
  markComplete = (id) => {
    this.setState({ todos: this.state.todos.map(todo => {
      if(todo.id === id){
        todo.completed = !todo.completed;
      }
      return todo;
    })});
  }
  //Delete Todo
  delTodo = (id) => {
    axios.delete(`https://jsonplaceholder.typicode.com/todos/$(id)`)
    .then(res =>       //spread operator??
      this.setState({ todos: [...this.state.todos.filter(todo => todo.id
        !== id)]})
        );

  }

    //Add Todo Item
    //make POST request to JSON placeholder
  addTodo = (title) => {
    // const newTodo = {
    //   id: uuid.v4(),
    //   title: title,
    //   completed: false
    // }
    axios.post('https://jsonplaceholder.typicode.com/todos', {
      title,
      completed: false
    })
    .then(res => this.setState({todos: 
      // [...this.state.todos, newTodo]
      [...this.state.todos, res.data]
    })
    );
  }

  render(){
    // console.log(this.state.todos)
    return (
      <Router>
        <div className="App">
          <Header />
          <Route exact path="/" render={props => (
            <React.Fragment>
                <AddTodo addTodo={this.addTodo} />
                {/* pass to Todos app as property */}
                <Todos todos={this.state.todos} markComplete={this.markComplete}
                delTodo={this.delTodo} />
            </React.Fragment>
          )} />

          <Route exact path="/about" component={About} />
          
        </div>
      </Router>
    );
    }
}

export default App;
