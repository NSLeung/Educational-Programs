import React, { Component } from 'react';
import { Text, View, Image } from 'react-native';

class Clock extends React.Component {
  // add constructor here that takes in props, necessary for Clock Component objects
  constructor(props){
    super(props);
    this.state = {date: new Date()};
  }
  
  //main lifecycle methods
  componentDidMount(){
    this.timerID = setInterval(
      ()=>this.tick(),
      1000
    );
  }
  componentWillUnmount(){
    clearInterval(this.timerID);
  }

  //tick function
  tick(){
    this.setState({
      date: new Date()
    });
  }

  render() {
    return (
      <View>
        <Text h1>Hello, boo! This is {this.props.clockID}</Text>
        <Text h2>It is {this.state.date.toLocaleTimeString()}.</Text>
      
      </View>
    );
  }
}

export default class Main extends Component{
  render() {
    return(
      <View style={{alignItems: 'center', top: 50}}>
      <Clock clockID="clock1"/>
      {/* <Clock/> */}
      </View>
    );
  }
}
// ReactDOM.render(
//   <Clock />,
//   document.getElementById('root')
// );

// export default Clock;