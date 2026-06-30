import { useState } from "react";

export default function Button({initial_count}) {
    
    const [count,setCount] = useState(initial_count)

    const handleClick = () => {
        console.log("Contador: ", count);
        setCount(count+1);
    }

    console.log("Mi boton: ", count)
    return (<button onClick={handleClick}>{count}</button>)
}