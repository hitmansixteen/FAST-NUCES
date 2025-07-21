import { useState ,useEffect} from 'react';
import useSWR from 'swr';
function LastSalesPage(props){

    const [sales,setSales]=useState(props.salesArr);
    const [load,setLoad]=useState(false)
 
    useEffect(()=>{
        setLoad(true);
        fetch("https://aslam-aa561-default-rtdb.firebaseio.com/lastsales.json").then(res=>res.json()).then(data=>{
            const salesArray=[]
            for(let key in data)
            {
                salesArray.push({
                    id:key,
                    username:data[key].userName,
                    volume:data[key].volume
                })
            }
            setSales(salesArray)
            setLoad(false)
        })
    },[])

    if(!sales ){
        return <p>Loading...</p>
    }
    return(
        <div>
            <ul>
                {sales.map(obj=>{
                    return <li key={obj.id}>{obj.username} has {obj.volume}</li>
                })}
            </ul>
        </div>
    )
}

export async function getStaticProps(){
     return fetch("https://aslam-aa561-default-rtdb.firebaseio.com/lastsales.json").then(res=>res.json()).then(data=>{
            const salesArray=[]
            for(let key in data)
            {
                salesArray.push({
                    id:key,
                    username:data[key].userName,
                    volume:data[key].volume
                })
            }
            console.log(salesArray)
            return {
                props:{
                    salesArr:salesArray
                }
            }
            
        })

    
}

export default LastSalesPage;