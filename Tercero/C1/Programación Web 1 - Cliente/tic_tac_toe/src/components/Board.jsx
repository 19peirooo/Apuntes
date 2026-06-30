import Square from "./Square"

export default function Board({board, handleClick}) {

    return (
        <div id = "board">
            {board.map((item, index) => <Square value = {item} idx = {index} handleClick={handleClick}></Square>)}
        </div>  
    );

}