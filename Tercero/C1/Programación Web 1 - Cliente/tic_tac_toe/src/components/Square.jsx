export default function Square({idx,value,handleClick}) {
    const disable = (value != '')
    return (
        <button id={`id${idx}`} onClick={() => handleClick(idx)} disabled={disable}>{value}</button>
    );
}