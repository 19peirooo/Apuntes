import Paisaje from "./Paisaje.jsx"
import winterImg from "/winter.jpg"
import springImg from "/spring.jpg"
import summerImg from "/summer.jpg"
import autumnImg from "/autumn.jpg"

const estaciones = [
    {nombre:"Invierno", ruta: winterImg},
    {nombre:"Primavera", ruta: springImg},
    {nombre:"Verano", ruta: summerImg},
    {nombre:"Otoño", ruta: autumnImg}
]

export default function Estaciones() {
    return(
        <>
            {estaciones.map(item => <Paisaje key={item.nombre} estacion={item.nombre} ruta={item.ruta}/>)}
        </>
    );
}