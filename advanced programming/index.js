import { useState ,useEffect} from 'react';
import useSWR from 'swr';
function LastSalesPage(){

    const [sales,setSales]=useState();
    const fetcher = (url) => fetch(url).then((res) => res.json());
    const {data,error}=useSWR("https://aslam-aa561-default-rtdb.firebaseio.com/lastsales.json",fetcher)
 
    //now using this useEffect hook only to set state, no api calling from here
    useEffect(()=>{
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
    },[data])

    if(!sales || !data){
        return <p>Loading...</p>
    }
    if(error)
    {
        return <p>Failed to Load</p>
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


export default LastSalesPage;