var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

/**
 * Escreva a sua solução aqui
 * Code your solution here
 * Escriba su solución aquí
 */
 
let animais = {
    "vertebrado,ave,carnivoro": "aguia",
    "vertebrado,ave,onivoro": "pomba",
    "vertebrado,mamifero,onivoro": "homem",
    "vertebrado,mamifero,herbivoro": "vaca",
    "invertebrado,inseto,hematofago": "pulga",
    "invertebrado,inseto,herbivoro": "lagarta",
    "invertebrado,anelideo,hematofago": "sanguessuga",
    "invertebrado,anelideo,onivoro": "minhoca"
}

let coluna = lines.shift();
let especie = lines.shift();
let dieta = lines.shift();

console.log(animais[`${coluna},${especie},${dieta}`]);