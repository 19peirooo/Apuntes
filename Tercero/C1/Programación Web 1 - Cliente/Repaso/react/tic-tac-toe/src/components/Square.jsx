import "./Board.css"

export default function Square({idx,player,handleClick}) {
    if (player === 'X') {
        return (
            <button id={`id_${idx}`} onClick={() => handleClick(idx)} className="player_x">{player}</button>
        );
    } else if (player === 'O') {
        return (
            <button id={`id_${idx}`} onClick={() => handleClick(idx)} className="player_o">{player}</button>
        );
    } else {
        return (
            <button id={`id_${idx}`} onClick={() => handleClick(idx)}>{player}</button>
        );
    }
    
}   