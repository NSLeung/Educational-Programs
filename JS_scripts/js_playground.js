const materials = [
    'Hydrogen',
    'Beryllium',
    'Helium'
]

// console.log(materials.map(material => material.length));

//BEFORE 
hello = function(){
    return "Hello, World";
}

//WITH ARROW FUNCTION
hello2 = () => {
    return "Hello 2, World";
}
hello3 = (val) => "Hello " + val;

hello4 = val => "Hello " + val;

hello5 = val =>{
    val += " added something";
    return "Hello " + val;
}
console.log(hello5("Bobby"));

