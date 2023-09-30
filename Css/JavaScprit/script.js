const circle = document.querySelector('circle');

let element = document.createElement('i');

element.style.width = '100px';
element.style.height = '100px';
element.style.backgroundColor = 'red';
element.style.position = 'absolute';
element.style.borderRadius = '50%';

circle.appendChild(element);