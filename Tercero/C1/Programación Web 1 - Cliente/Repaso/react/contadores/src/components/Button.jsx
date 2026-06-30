
export default function Button({name,handleClick}) {
    return (
        <button onClick={handleClick}>{name}</button>
    );
}