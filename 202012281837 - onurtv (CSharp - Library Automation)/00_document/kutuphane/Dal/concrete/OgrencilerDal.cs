using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dal.Abstract;
using Dal.genericRepository.Concrete;
using entities.Concrete;
namespace Dal.concrete
{
    public class OgrencilerDal : RepositoryBase<ogrenciler>, IOgrencilerDal
    {
    }
}
