import Square from "./Square";
import './Board.css'

export default function Board({board,handleClick}) {

    return (
        <div className="board">
            {board.map((item,index) => <Square idx={index} player={item} handleClick={handleClick}></Square>)}
        </div>
    )

}