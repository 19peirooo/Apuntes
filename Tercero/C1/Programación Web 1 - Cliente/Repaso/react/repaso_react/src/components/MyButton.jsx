
export default function MyButton({nombre,msg}) {

    const handleClick = () => {
        alert(msg)
    }

    return (
        <button onClick={handleClick}>{nombre}</button>
    );
}