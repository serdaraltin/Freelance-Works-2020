using Dal.genericRepository.Abstract;
using entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dal.Abstract
{
    //cezalara ait soyut sınıfın tanımı
    public interface ICezalarDal:IRepositoryBase<cezalar>
    {
    }
}
