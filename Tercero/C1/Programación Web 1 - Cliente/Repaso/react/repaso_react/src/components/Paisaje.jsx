import './Paisaje.css'

export default function Paisaje({estacion,ruta}) {
    return (
        <div>
            <h1>{estacion}</h1>
            <img className="estacion" src={ruta} alt={estacion}/>
        </div>
    );
}