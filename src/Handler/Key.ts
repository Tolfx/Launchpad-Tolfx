import Launchpad from 'launchpad-mini';
import { readdirSync } from "fs";
import { Dir } from '../Config';

 export default function Keys(pad: Launchpad)
{
    // Get all of the keys.
    const keys: any[] = [];
    const commands = readdirSync(Dir+`/build/Keys`).filter(f => f.endsWith(".js"));
    for (let file of commands) 
    {
        let pull = require(`../Keys/${file}`);
        if (pull.row && pull.column)
        {
            keys.push(pull);
            setTimeout(() => {
                pad.col((pull.run ? pull.color ?? pad.green : pad.red), [ parseInt(pull.row), parseInt(pull.column) ])
            }, 1000)
        }
        continue;
    }

    pad.on('key', data => {
        if(data.pressed)
        {
            const row = (pad.pressedButtons[0][0]).toString();
            const column = (pad.pressedButtons[0][1]).toString();
            const cmd = keys.find(e => e.row === row && e.column === column);
            if(cmd)
            {
                cmd.run();
            }
        }
    });
}